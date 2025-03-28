# RSA文本加解密系统

这是一个使用RSA算法实现的文本加解密系统，支持生成密钥对、加密和解密操作。

## 功能概述

- **密钥生成**：随机生成两个大素数并计算模数和公私钥对。
- **加密**：对输入的文本文件进行加密，并将结果输出到加密文件。
- **解密**：对加密文件进行解密，并将结果输出到解密文件。

## 代码结构

- `main()`：程序入口，提供用户操作菜单。
- `prime_random()`：生成随机大素数。
- `erand()`：生成与模长互素的随机数。
- `rsad()`：计算解密密钥。
- `tencrypto()`：对文件进行加密。
- `tdecrypto()`：对文件进行解密。
- 大数运算库：实现大数的加、减、乘、除、模运算。

## 使用方法

1. **编译代码**：
   使用以下命令编译代码：
   ```sh
   gcc -o rsa_encryptor rsa_encryptor.c
   ```

2. **运行程序**：
   ```sh
   ./rsa_encryptor
   ```

3. **选择操作**：
   - 输入 `1` 生成密钥对并加密文件。
   - 输入 `2` 解密文件。
   - 输入 `3` 退出程序。

## 注意事项

- 确保输入的文件存在且路径正确。
- 加密文件默认输出为 `encryfile.txt`，解密文件输出为 `decryfile.txt`。
- 该实现主要用于学习和测试，未进行安全性优化。
