# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/cihangir/esp/v5.0.5/esp-idf/components/bootloader/subproject"
  "/home/cihangir/Desktop/Software_Project/Capstone_Project/Embedded_Section/Code_section/ESP32_VS_Code/Project_Code/sample_project/build/bootloader"
  "/home/cihangir/Desktop/Software_Project/Capstone_Project/Embedded_Section/Code_section/ESP32_VS_Code/Project_Code/sample_project/build/bootloader-prefix"
  "/home/cihangir/Desktop/Software_Project/Capstone_Project/Embedded_Section/Code_section/ESP32_VS_Code/Project_Code/sample_project/build/bootloader-prefix/tmp"
  "/home/cihangir/Desktop/Software_Project/Capstone_Project/Embedded_Section/Code_section/ESP32_VS_Code/Project_Code/sample_project/build/bootloader-prefix/src/bootloader-stamp"
  "/home/cihangir/Desktop/Software_Project/Capstone_Project/Embedded_Section/Code_section/ESP32_VS_Code/Project_Code/sample_project/build/bootloader-prefix/src"
  "/home/cihangir/Desktop/Software_Project/Capstone_Project/Embedded_Section/Code_section/ESP32_VS_Code/Project_Code/sample_project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/cihangir/Desktop/Software_Project/Capstone_Project/Embedded_Section/Code_section/ESP32_VS_Code/Project_Code/sample_project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/cihangir/Desktop/Software_Project/Capstone_Project/Embedded_Section/Code_section/ESP32_VS_Code/Project_Code/sample_project/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
