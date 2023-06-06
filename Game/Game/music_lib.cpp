#include<AL/al.h>
#include <AL/alc.h>
#include <fstream>
#include<string>
#include<ctime>
#include<thread>
#include<iostream>


clock_t start;
bool control = false;

bool isBigEndian()
{
    int a = 1;
    return !((char*)&a)[0];
}

int convertToInt(char* buffer, int len)
{
    int a = 0;
    if (!isBigEndian())
        for (int i = 0; i < len; i++)
            ((char*)&a)[i] = buffer[i];
    else
        for (int i = 0; i < len; i++)
            ((char*)&a)[3 - i] = buffer[i];
    return a;
}

char* loadWAV(const char* fn, int& chan, int& samplerate, int& bps, int& size)
{
    const int type = 4;
    char buffer[type];
    std::ifstream in(fn, std::ios::binary);
    in.read(buffer, type);
    if (strncmp(buffer, "RIFF", type) != 0)
    {
        std::cout << "this is not a valid WAVE file" << std::endl;
        return NULL;
    }
    in.read(buffer, type);
    in.read(buffer, type);      //WAVE
    in.read(buffer, type);      //fmt
    in.read(buffer, type);      //16
    in.read(buffer, type / 2);      //1
    in.read(buffer, type / 2);
    chan = convertToInt(buffer, type / 2);
    in.read(buffer, type);
    samplerate = convertToInt(buffer, type);
    in.read(buffer, type);
    in.read(buffer, type / 2);
    in.read(buffer, type / 2);
    bps = convertToInt(buffer, type / 2);
    in.read(buffer, type);      //data
    in.read(buffer, type);
    size = convertToInt(buffer, type);
    char* data = new char[size];
    in.read(data, size);
    return data;
}

void PlaySound()
{
    int channel, sampleRate, bps, size;;
    char* data = loadWAV("2-1.wav", channel, sampleRate, bps, size);
    ALCdevice* device = alcOpenDevice(NULL);
    if (device == NULL)
    {
        std::cout << "cannot open sound card" << std::endl;
        return;
    }
    ALCcontext* context = alcCreateContext(device, NULL);
    if (context == NULL)
    {
        std::cout << "cannot open context" << std::endl;
        return;
    }
    alcMakeContextCurrent(context);

    unsigned int bufferid, format;
    alGenBuffers(1, &bufferid);
    if (channel == 1)
    {
        if (bps == 8)
        {
            format = AL_FORMAT_MONO8;
        }
        else {
            format = AL_FORMAT_MONO16;
        }
    }
    else {
        if (bps == 8)
        {
            format = AL_FORMAT_STEREO8;
        }
        else {
            format = AL_FORMAT_STEREO16;
        }
    }
    alBufferData(bufferid, format, data, size, sampleRate);
    unsigned int sourceid;
    alGenSources(1, &sourceid);
    alSourcei(sourceid, AL_BUFFER, bufferid);
    alSourcePlay(sourceid);

    while (true)
    {

    }

    alDeleteSources(1, &sourceid);
    alDeleteBuffers(1, &bufferid);

    alcDestroyContext(context);
    alcCloseDevice(device);
    delete[] data;
    return;
}

void ContinueSound()
{

    if (!control)
    {
        control = true;
        start = clock();
        std::thread myThread(PlaySound);
        myThread.detach();
    }
    if (start + 43000 <= clock())
    {
        control = false;
    }

}