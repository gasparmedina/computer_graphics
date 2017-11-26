#!/bin/bash

if [ `uname` == "Linux" ]
then
	make -f Makefile1.linux all
else
	make -f Makefile.mac all
fi

