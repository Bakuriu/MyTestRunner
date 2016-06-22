#!/bin/bash

LIBRARY_DIR="$(kf5-config --qt-plugins)"
DESKTOP_DIR="$(kf5-config --path services | awk -F ':' '{ print $1 }')"
LIBRARY_NAME="$(grep X-KDE-Library plasma-runner-mytestrunner.desktop | awk -F '=' '{ print $2 }').so"

echo "Destination directory for the plug-in library is: ${LIBRARY_DIR}"
echo "Destination directory for the .desktop file is: ${LIBRARY_NAME}"


echo "Starting builing process..."
echo "Running qmake"
qmake

echo "Running make"
make

echo "Installing the library file"
cp libMyTestRunner.so.1.0.0 "${LIBRARY_DIR}/${LIBRARY_NAME}"

echo "Installing the desktop file"
cp plasma-runner-mytestrunner.desktop "${DESKTOP_DIR}"

echo "Clearing directory"

rm libMyTestRunner.so*
rm *.o
rm moc_*
rm Makefile

echo "Restarting KRunner..."

kquitapp krunner && krunner &
