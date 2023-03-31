/*
 * 1. Реализовать чтение заголовков файлов форматов. Проверить работоспособность
можно по примерам.
a. ICO: ICONDIR и ICONDIRENTRY
*/

#include <iostream>
#include <fstream>

typedef short int WORD;
typedef char SHWORD;
typedef int LWORD;


#pragma pack(push, 2)

struct ICONDIR {
    WORD Reserved;
    WORD Type;
    WORD Count;
};

struct ICONDIRENTRY {
    SHWORD Width;
    SHWORD Height;
    SHWORD ColorCount;
    SHWORD Reserved;
    WORD Planes;
    WORD BitCount;
    LWORD BytesInRes;
    LWORD ImageOffset;
};

#pragma pack(pop)

int main() {


    std::ifstream file("rotation.ico", std::ios::binary);
    ICONDIR icon_dir;
    file.read((char*)&icon_dir, sizeof(icon_dir));
    std::cout << "\t--ICONDIR--" << std::endl;
    std::cout << "\tReserved: " << icon_dir.Reserved << std::endl;
    std::cout << "\tType: " << icon_dir.Type << std::endl;
    std::cout << "\tCount: " << icon_dir.Count << std::endl << std::endl;

    ICONDIRENTRY dir_entry;
    file.read((char*)&dir_entry, sizeof(dir_entry));
    file.close();

    std::cout << "\t--ICONDIRENTRY--" << std::endl;
    std::cout << "\tWidth: " << (short)(dir_entry.Width) << std::endl;
    std::cout << "\tHeight: " << (short)(dir_entry.Height) << std::endl;
    std::cout << "\tColorCount: " << (short)(dir_entry.ColorCount) << std::endl;
    std::cout << "\tPlanes: " << dir_entry.Planes << std::endl;
    std::cout << "\tBitCount: " << dir_entry.BitCount << std::endl;
    std::cout << "\tBytesInRes: " << dir_entry.BytesInRes << std::endl;
    std::cout << "\tImageOffset: " << dir_entry.ImageOffset << std::endl;

    return 0;
}
