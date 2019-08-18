# Unicorn Library

The Sha1 hash for this lib is:
```
C:\Users\ch3rn0byl\Desktop\Visual Studio\Project\Project>certutil -hashfile unicorn_static.lib sha1
SHA1 hash of unicorn_static.lib:
f17eeb9dcc49290956990343d4463cf494fda36c
CertUtil: -hashfile command completed successfully.
```

Test.cpp can be compiled as a sample proggie

```
C:\Users\ch3rn0byl\Desktop>cl test.cpp /EHsc
Microsoft (R) C/C++ Optimizing Compiler Version 19.22.27905 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

test.cpp
Microsoft (R) Incremental Linker Version 14.22.27905.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:test.exe
test.obj

C:\Users\ch3rn0byl\Desktop>test.exe
[+] Emulating XOR EAX, EAX...
[+] Writing 0x31337 to eax...
[+] Done!
[+] EAX before: 31337
[+] EAX after: 0

C:\Users\ch3rn0byl\Desktop>
```
