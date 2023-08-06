### launch.json
각 운영체제에 맞게 extention을 셋팅 하였다면 아래와 같은 파일이 생성 되었을껍니다.
여기에 ***디버깅시*** 테스트케이스를 다수 손 쉽게 넣을 수 있도록 설정하려고 합니다.
***※ 아래는 macOS clang설정 입니다.***
```
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "C/C++: clang++ build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": true,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "lldb",
      "preLaunchTask": "C/C++: clang++ build active file"
    }
  ]
}

```

***위 설정에서 아래와 같이 인풋 셋팅을 해줍니다.***

```
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "C/C++: clang++ build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": true,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "lldb",
      "preLaunchTask": "C/C++: clang++ build active file"
      "setupCommands": [
        {
          "text": "settings set target.input-path ${fileDirname}/input"
        }
      ]
    }
  ]
}
```

이렇게 설정하고 디버깅(F5) 시에 input파일의 테스트 케이스가 자동으로 들어가는걸 확인할 수 있습니다. ***단, input파일이 없으면 안됩니다.***