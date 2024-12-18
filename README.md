# pearlOS: Operating system

[![Build](https://img.shields.io/github/actions/workflow/status/ElisStaaf/pearlOS/build.yml?logo=Github&labelColor=17181B&label=Build)](/)
[![Version](https://img.shields.io/badge/Version-NET%2f2-FF0062?labelColor=17181B)](/)
[![C17](https://img.shields.io/badge/Standard-C17-A8B9CC?logo=C&labelColor=17181B)](/)
[![BuildSys](https://img.shields.io/badge/Build%20System-GNU%20Make-0F6713?logo=GNU&labelColor=17181B&logoColor=898484)](/)  

pearlOS is an awesome operating system based of the [pidi-os](https://github.com/GandelXIV/pidi-os)
project that was sadly discontinued, but I *highly* recommend you to check out the new rust-based
operating system made by the same author; [RezOS](https://github.com/GandelXIV/RezOS)
But ofcourse only do that *after* you check out this project! pearlOS was made
for me to learn operating system things and also to become better at C and Assembly.

[![pearlOS](https://github.com/ElisStaaf/pearlOS/raw/main/prod/boot.png)](https://github.com/ElisStaaf/pearlOS)

## Requirements

* [Make](https://www.gnu.org/software/make)
* [NASM](https://nasm.us)
* [GCC](https://gcc.gnu.org)
* [QEMU](https://www.qemu.org)

## Installation

> [!NOTE]
> Compilation is only guaranteed on linux with *GCC ISO C17*,
> but it is also possible in Windows with virtualization
> solutions like WSL (on Windows 11) or hyperV.

PearlOS prides itself in it's incredibly easy installation, as it only requires 3 commands!
It's very easy to install, firstly clone the repo:
```sh
git clone https://github.com/ElisStaaf/pearlOS
```
After going into the repo directory, run configure and then make:
```sh
./configure
make
```
Lastly, run the generated image at dist/pearl.bin:
```sh
qemu-system-i386 dist/pearl.bin
```
This will start up a QEMU session with the image, and you
can run the OS.

## Uninstalling

To uninstall, simply run:
```sh
make clean
```

## Contributing

See [CONTRIBUTING.md](/CONTRIBUTING.md).

## Activity

I'm a bit inconsistent on when I actually, y'know, maintain and update this,
but I can assure you, even if you see a 1-month pause, THE PROJECT IS NOT DEAD.
If the project dies, you can expect archival or at least a message.

## License

Unless expicitly stated, every single *modified* file in this project is licensed
under the *Apache 2.0 License*, while the *unmodified* files are licensed under *MIT*.
The "SPDX-License-Identifier" rule obviously overrides this option, and is how you
explicitly state a different license. See [LICENSE](/LICENSE) for the 2 main licenses.
