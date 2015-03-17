#!/bin/sh	

echo "Add repository"
sudo add-apt-repository ppa:ubuntu:toolchain-r/test -y

echo "Update repositories"
sudo apt-get update -y

echo "Install g++ 4.9"
sudo apt-get install g++-4.9 -y

echo "Change symbolic lin in /usr/bin"
cd /usr/bin && sudo rm g++ && sudo ln-s g++-4.9 g++
