  #include <iostream>

int main()
{
    unsigned short int A1 = 65535, A2 = 65535, A3 = 65535, B1 = 65535, B2 = 65535, B3 = 65535;
    int G1=0, G2=0, G3=0;
    __asm
    {
        mov eax, 0
        mov ax, A3;
        mov G3, eax;
        mov eax, 0
        mov ax, B3;
        add G3, eax;
    }

    __asm
    {
        mov eax, 0;
        mov ax, A2;
        mov G2, eax;
        mov eax, 0;
        mov ax, B2;
        add G2, eax;
        mov edx, 99999;
        cmp G2, edx;
        ja above
            mov eax, 0;
        above:
            sub G2, 100000
            add G3, 1;
    }

    __asm
    {
        mov eax, 0;
        mov ax, A1;
        mov G1, eax;
        mov eax, 0;
        mov ax, B1;
        add G1, eax;
        mov edx, 99999;
        cmp G1, edx;
        ja above_
            mov eax, 0;
    above_:
        sub G1, 100000
            add G2, 1;
    }

    std::cout << G3 <<" " << G2 << " " << G1 << std::endl;
    std::cout << std::hex << G3 << " " << G2 << " " << G1 << std::endl;
}

