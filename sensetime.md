### 打包APK

> 更新Demo，并发布版本

1. 从研究组获得最新的 `teemodel.bin` ,  `st_compact.o` , （`\include`可选），在项目中做相应的替换。
2. 指定版本号，在`build.gradle`中指定。
3. Android Studio > Build > Build Bundle(s) or APK(s) > Build APK(s)
4. 生成的APK位于`build/outputs/apk/debug/FaceUnlock-hw-v1.49-2019.10.10.apk`。

**在手机端安装APK**

1. 卸载手机端的软件
2. `adb install <name>.apk`

**一键脚本**

```sh
./build-apk.sh <sdk-path> version
```
