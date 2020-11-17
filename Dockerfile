FROM fedora:30

RUN dnf -y update

RUN curl --silent --location https://dl.yarnpkg.com/rpm/yarn.repo | tee /etc/yum.repos.d/yarn.repo

RUN dnf install -y cmake ninja-build expat-devel zlib-devel redis hiredis-devel \
libev-devel uuid-devel libuuid-devel systemd-devel openssl-devel arm-none-eabi-gcc-cs-c++ \
arm-none-eabi-newlib gcc-c++ qt5-devel alsa-lib-devel nodejs mbedtls-devel binutils-devel \
qt5-qtbase-gui qt5-devel xz findutils python2 python3 tar which perl file bzip2 git yarn-1.12.3 \
eigen3-devel chrpath cpio diffstat ed hostname patch wget texinfo rsync bc gdb 


CMD ["/bin/bash"]