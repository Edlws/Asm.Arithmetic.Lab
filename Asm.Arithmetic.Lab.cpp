  #include <iostream>

int main()
{
    unsigned short int A1 = 65535, A2 = 10000, A3 = 65535, B1 = 65535, B2 = 55535, B3 = 65535;
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
        add ax, B2;
        jc cf1
            mov G2, eax;
        jmp end1;
    cf1:
        add eax, 10000000000000000b;
        cmp eax, 100000;
        jae ae1;
        mov G2, eax;
        jmp end1;
    ae1:
        sub eax, 100000;
        mov G2, eax
        add G3, 1;
    end1:
    }

    __asm
    {
        mov eax, 0;
        mov ax, A1;
        add ax, B1;
        jc cf2
        mov G1, eax;
        jmp end2;
    cf2:
        add eax, 10000000000000000b;
        cmp eax, 100000;
        jae ae2;
        mov G1, eax;
        jmp end2;
    ae2:
        sub eax, 100000;
        mov G1, eax
        add G2, 1;
    end2:
    }

                std::cout << G3 << " " << G2 << " " << G1 << std::endl;
    std::cout << std::hex << G3 << " " << G2 << " " << G1 << std::endl;
    return 0;
}

