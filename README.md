# hpp-builder
hppbuilder is a simple class header file (.hpp) generator for linux.

# How to install
Run these commands to clone hpp-builder repository and build its source files.
```
git clone https://github.com/Veltiktok/hpp-builder.git
cd hpp-builder
make
```
Note that the `make` command will add an alias to your `.bashrc` to run hpp-builder from any directory.
So if you are using any other software other than bash you have to modify the `BASHRC = ~/.bashrc` variable in Makefile.
# How to use
Generate your className.hpp by using the command:
`hppbuild <className>`

# License
This software is under Apache License 2.0, see it [here](https://github.com/Veltiktok/hpp-builder/blob/main/LICENSE).
