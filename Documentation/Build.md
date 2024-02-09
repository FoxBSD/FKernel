# Building the FKernel

The FKernel build process require some tools:

- Compiler: Clang
- Mounter: Nasm
- Build System: Xmake
- Linker: Ld.lld

But has some hidden tools used to run this Kernel in a virtual machine:

- qemu: virtual machine to boot the kernel

The principal ideia is use a dynamic tools with deterministic types to agnostic building.

If you want compile with WSL, Linux, BSD or MacOSX the kernel be compiled and the result is the same to all enviroments.

From this the principal ideia is use a portable mounter and portable compiler Clang / Nasm make this and xmake doesnt fail in portability.

## Building Process in Linux:

To building this project in Linux if you already has the principal tools cited above do you need run the command:

```bash
xmake -v
```

Xmake is run the building process + linking process and generate a kernel iso to you run the FKernel.bin in a virtual machine with command:

```bash
xmake run
```

---

## Compiling Process

The process of build following this process:

```
[Build Files] -> (Clang) -> [Object Files] -> (Linker) -> <FKernel.bin>
```

But if we looking the xmake process, the process is:

```
(cppcheck // clang-format) -> [Build Files] -> (Clang) -> [Object Files] -> (Linker) -> <FKernel.bin>
```

With helpers, we can improve the compiling rules to build the project
