# Data Exchange Library (windows) based on shared memory


## Features
* read/write lock
* high efficiency
* shared memory

## Requirements
* windows OS

## Usage examples

#### inertial sensor（Please include oxts2000.h）

* create an instance，set memory name and size
```
 ProceedDataExchange data(TEXT("Global\\memoryName"), size);
```

* write package
```
 data.writePackage(&variable, sizeof(variable), dataID, blockFlag);
```

* Read package
```
 data.readPackage(&variable, sizeof(variable), dataID, blockFlag);
```

## Help and Support
contact: 15lwang@tongji.edu.cn
