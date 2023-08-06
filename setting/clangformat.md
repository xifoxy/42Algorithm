### ***[clang-format](https://clang.llvm.org/) 이란?***

### 설치
- [Homebrew](https://formulae.brew.sh/formula/clang-format)
- [Extention](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)

### 적용 - Setting.json
```
{
    "editor.formatOnSave": true,
    "C_Cpp.clang_format_fallbackStyle": "Google",
    "clang-format.executable": "/opt/homebrew/bin/clang-format",
}
```

저장시 구글 스타일로 자동으로 맞춰주는 예시이다. 이렇게 특정 스타일 옵션을 사용할 수 있고, 커스텀 해서 사용할 수 있다. 정해진 스타일을 파일화 하여 직접 커스텀 하는 방법도 있으니 Docs를 이용해보자.