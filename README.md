# hpp-builder
hppbuilder is a simple class header file (.hpp) generator for linux.\
It simply replace every occurence of tags 'className' and 'CLASSNAME' from the [template file](https://github.com/Veltiktok/hpp-builder/blob/main/hpptemplate.hpp).\
Feel free to modify it as you want.\
I plan in a future release to add an option to add any tags you want in template and specify their values ​​at runtime.
# How to install
Run these commands to clone hpp-builder repository and build its source files.
```
git clone https://github.com/Veltiktok/hpp-builder.git
cd hpp-builder
make
```
Note that the `make` and `make fclean` commands will add and remove an alias respectively to your `.bashrc` to run hpp-builder from any directory.\
So if you are using any other software other than bash you have to modify the `BASHRC = ~/.bashrc` variable in Makefile.\
(Example: `BASHRC = ~/.zshrc` for zsh)
# How to use
Generate your className.hpp by using the command:
`hppbuild <className>`

# License
This software is under Apache License 2.0, see it [here](https://github.com/Veltiktok/hpp-builder/blob/main/LICENSE).
