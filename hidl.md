人脸识别身份堆栈是android 10的新实现，引入了IBiometricsFace.hal, IBiometricsFaceClientCallback.hal和types.hal

BiometricPrompt API 包括 人脸识别、指纹识别、虹膜识别等生物识别身份验证方法，
Face HAL 会与如下所有组件交互：

FaceManager:是一个私有接口，用户维护与FaceService之间的连接。应用无权访问，必须使用BiometricPrompt。
FaceService: 实现用于管理对人脸识别身份验证硬件的访问权限，包含基本的注册和身份验证状态机
faced:是linux可执行文件，用于实现供FaceService使用的Face 1.0 HIDL接口，它会将自身注册为IBiometricsFACE@1.0方便FaceService可以找到它。

要实现FaceHIDL，需要在某个供应商专用库中实现 IBiometricsFace.hal的所有方法。
错误消息：
采集消息：注册或身份验证期间会传递采集消息，每个序数在FaceAuthenticationManager.java文件中都有一条关联消息，只要提供相应的帮助字符串，就可以添加供应商专用消息

硬件：不仅需要TEE来确保处理和识别的安全，还需要安全的摄像头硬件来防止人脸识别身份验证的注入式攻击。
由于硬件差异性过大，因此必须开发基于特定硬件的驱动程序来实现人脸识别身份验证，因此faced没有参考实现。


方法：异步消息
必须立即返回到框架，会导致系统运行速度太慢。
setCallback()由FaceService调用使得所有消息回归本身。
setActiveUser() 设置为其应用后续所有HAL操作的活跃用户，在再次调用该方法之前，始终针对此用户进行身份验证。
revokeChallenge() 通过使generateChallenge()生成的质询代码无效来完成安全交易。
enroll() 注册用户的人脸。
cancel() 取消当前操作，将faced返回到闲置状态
enumerate() 
remove() 移除与活跃用户关联的某个或所有人脸模板
authenticate() 对活跃用户进行身份验证
userActivity() 
resetLockout() 如果识别被拒绝次数太多，faced需要进入锁定状态，把剩余时间显示给用户。

同步消息：
generateChallenge() 
setFeature()
getFeature()
getAuthenticatorId() 返回与当前人脸集相关的标识符。

评价指标
冒名接受率 IAR：生物识别模型接受意图模仿已知良好样本输入的概率，“冒名攻击”
期盼接受率 SAR：生物识别模型接受事先录制的已知良好样本的概率，“欺骗攻击”
错误接受率 FAR: 模型错误地接受随机选择的有误输入的概率。



./hardware/interfaces/biometrics/fingerprint/2.1/IBiometricsFingerprint.hal

$ find ./ -name BiometricPrompt.java
./frameworks/base/core/java/android/hardware/biometrics/BiometricPrompt.java


对于语音解锁，该指标会测量使用已录制的用户语音样本成功解锁的概率


