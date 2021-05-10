# Levine Hall 4th Floor in UE4

Developed with Unreal Engine 4.23.1. This project holds a 3D model of Levine Hall 4th floor of SEAS building of University of Pennsylvania, created from Autodesk Revit 2019.

During gameplay, it also does the following:
- saves the 3D location of the active actor into `csv/actorLocation.csv` upon every mouse right click.
- sets up a communication between itself and ROS.

This project is standalone software and it can be launched by itself. However, it is designed to be one part of the [CAD2CAV project](https://github.com/mlab-upenn/ISP2021-cad2cav) of F1/10 Autnomous Racing Group of University of Pennsylvania. 

## System Requirements
This project is tested in Ubuntu 20.04 LTS.

## Usage
1. Before running the gameplay, **please make sure the folder `csv` is empty.**
2. In the folder where you install UE4, please run the following:

```bash
git clone --recursive https://github.com/shineyruan/unreal_levine_4.git ~/unreal_levine_4
cd ${UE4_ROOT}/Engine/Binaries/Linux
./UE4Editor ~/unreal_levine_4/Levine_4.uproject
```
3. In UE4 editor, compile all source codes and build the project.
4. Hit the "Play" button.

## Deployment
One can also deploy the project by clicking the "Launch" button in UE4 editor. Once launched succesfully, the shipping package can be found in `~/unreal_levine_4/Saved/StagedBuilds/LinuxNoEditor`. Go to this directory and type
```bash
./Levine_4.sh
```
In this scenario, the CSV file will be saved in `~/unreal_levine_4/Saved/StagedBuilds/LinuxNoEditor/Levine_4/csv/actorLocation.csv`.

