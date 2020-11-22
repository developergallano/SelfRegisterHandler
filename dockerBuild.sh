#!/bin/bash

args="${@}"
if [ -z args ]; then
    args="bash"
fi

readonly dockername="cpp-builder-inst"
readonly dockerimage="cpp-builder"

function install_code_extensions()
{
    code --install-extension ms-vscode-remote.remote-containers
    code --install-extension ms-vscode-remote.remote-ssh
    code --install-extension ms-vscode-remote.remote-ssh-edit
    code --install-extension ms-vscode-remote.remote-wsl
    code --install-extension ms-vscode-remote.vscode-remote-extensionpack
    code --install-extension ms-vscode.cmake-tools
    code --install-extension ms-vscode.cpptools
    code --install-extension ryu1kn.partial-diff
    code --install-extension tht13.html-preview-vscode
    code --install-extension twxs.cmake
    code --install-extension vikas.code-navigation
}

function docker_build()
{
    image_exist=$( docker images | grep cpp-builder)
    if [ -z "$image_exist" ]; then
        echo "building  docker image $dockerimage"
        docker build -t $dockerimage .    
    fi
}

function start_docker()
{
    docker volume create userhome

    docker run -ti --rm -i -d \
        --env LOCAL_USER_ID=$(id -u) \
        --workdir=$PWD \
        --name $dockername \
        -v $PWD:$PWD:Z \
        $dockerimage
        #-v userhome:/home/user:Z \

}

function exe_args()
{
    set +e
    
    echo "Running docker $dockername"

    docker exec --user $(id -u) -ti $dockername sh -c "$args"
}

function main_func()
{
    # code extension first
    install_code_extensions

    running=$(docker ps -s -f name=$dockername -q)
    if [ -z "$running" ]; then
        
        echo "Docker $dockername is NOT running"
        docker_build

        start_docker
    fi

    exe_args
}


main_func