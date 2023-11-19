#! /bin/bash

# Check arguments...
if [ $# -ne 1 ] ; then
    echo "usage: $0 <kppdir>"
    exit
fi

# Set directory...
kppdir=$1
REBUILD=1



# Set target directory...
# target=$(cd ../ && pwd)
export KPP_HOME=$(cd ../ && pwd)
export KPP_FLEX_LIB_DIR=$KPP_HOME

# Build KPP code... 
[ $REBUILD -eq 1 ] && cp ./Makefile $kppdir \
&& cp ./kpp_chem.h $kppdir \
&& cd $kppdir  \
&& $KPP_HOME/bin/kpp chem.kpp 

make clean \
&& make lib INFO=0 \
&& cp libkpp.a $target/lib \
&& cp *.h $target/include \
&& rm *.o
