add_rules("mode.debug", "mode.release")
set_policy("check.auto_ignore_flags", false)

set_filename("FKernel.bin")
set_targetdir("build")
set_objectdir("build/objs")

set_languages("c++17", "c90")

toolchain("FKernel_Compiling")
    set_kind("standalone")

    set_toolset("cc", "clang")
    set_toolset("cxx", "clang", "clang++")
    set_toolset("ld", "ld.lld")
    set_toolset("as", "nasm")

    on_check(function (toolchain) 
        local has_clang = import("lib.detect.find_tool")("clang")
        local has_lld = import("lib.detect.find_tool")("ld.lld")
        local has_nasm = import("lib.detect.find_tool")("nasm")

        return has_clang and has_lld and has_nasm
    end)

    on_load(function (toolchain) 
        local march = is_arch("x86_64", "x64") and "-m64" or "-m32"
        toolchain:add("cxflags", march)
    end)
toolchain_end()

local osdev_lld_flags
local osdev_clang_flags
local osdev_nasm_flags

if is_mode("debug") then 
    osdev_clang_flags = {
        "-ffreestanding",
        "-g",
        "-c",
        
    }

    osdev_lld_flags = {
        "-T Config/linker.ld",
        "--gdb-index",
        "--no-gnu-unique",
        "--no-gc-sections",
        "--no-nmagic"
    }

    osdev_nasm_flags = {
        "-f elf64",
        "-g"
    }

elseif is_mode("release") then 
    osdev_clang_flags = {
        "-ffreestanding",
        "-g"    
    }

    osdev_lld_flags = {
        "-T Config/linker.ld",
        "--gdb-index",
        "--no-gnu-unique",
        "--no-gc-sections",
        "--no-nmagic"
    }

    osdev_nasm_flags = {
        "-f elf64"
    }

end

target("FKernel")
    set_default(true)
    set_kind("binary")

    add_toolchains("FKernel_Compiling")

    add_cxflags(osdev_clang_flags)
    add_asflags(osdev_nasm_flags)
    add_ldflags(osdev_lld_flags)

    --add_includedirs("Include")
    --add_files("Src/Kernel/Core/**.cpp")
    add_files("Src/Kernel/Boot/**.asm")

    if is_plat("linux") then 
        before_build(function (target) 
            os.execv("bash Meta/Unix-Shell/run_cppcheck.sh")
        end)

        after_link(function (target) 
            os.execv("bash Meta/Unix-Shell/mount_mockos.sh")
        end)

       on_run(function (target)
            os.execv("bash Meta/Unix-Shell/run_mockos.sh")
        end)
    end
