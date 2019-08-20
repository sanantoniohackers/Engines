#Keystone Library

The SHA1 hash for this lib is: 
```
C:\Users\ch3rn0byl\Desktop\Visual Studio\Project\Project>certutil -hashfile keystone.lib sha1
SHA1 hash of keystone.lib:
5dc097e57ef41e0f4cbba83941ae50f4055fa55d
CertUtil: -hashfile command completed successfully.
```

As like Unicorn, you can just compile the test.cpp file to ensure it works. This code is directly from the keystone website
```
C:\Users\ch3rn0byl\Desktop>Project.exe
INC ecx; DEC edx = 41 4a
Assembled: 2 bytes, 2 statements
```

It is compiled as such:
```
C:\Users\ch3rn0byl\Desktop\keystone\buildtest2>cmake -DCMAKE_BUILD_TYPE=Release _DBUILD_SHARED_LIBS=OFF -DLLVM_TARGETS_TO_BUILD="all" /MT /O2 /Ob2 /DNDEBUG /EHsc -G "NMake Makefiles" ..
-- snipped output --
C:\Users\ch3rn\Desktop\keystone\buildtest2>nmake
-- snipped output --
```

Happy coding!
