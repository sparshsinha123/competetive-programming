#!/bin/bash
FILE=template.cpp
if [ -f "$FILE" ]; then
    echo "found template"
else 
    echo "template not found"
    echo "fetching it from parent"
    cp ../template.cpp .
fi

for i in A B C D E F
do
   echo "creating $i.cpp file..."
   cp template.cpp $i.cpp
   echo "opening $i.cpp.."
   code $i.cpp
done