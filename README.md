## Issue this repo reproduces:

When building for Release, constants and commands exported by a native module no longer work:

```C++
winrt::Microsoft::ReactNative::ConstantProviderDelegate winrt::reproducernwreleasebug::implementation::SimpleViewManager::ExportedViewConstants() noexcept
{
    return [](winrt::Microsoft::ReactNative::IJSValueWriter const& constantWriter)
    {
        WriteProperty(constantWriter, L"SimpleConstName", L"Sample Name");
    };
}

winrt::Windows::Foundation::Collections::IVectorView<winrt::hstring> winrt::reproducernwreleasebug::implementation::SimpleViewManager::Commands() noexcept
{
    auto commands = winrt::single_threaded_vector<hstring>();
    commands.Append(L"doSomething");
    return commands.GetView();
}
```

```JavaScript
const getConstant = (): String => {
  try {
    return UIManager.RNSimple.Constants.SimpleConstName;
  } catch(e) {
    return 'Some error occurred while getting the constant.'
  }
}

const getCommand = (): String => {
  try {
    return UIManager.RNSimple.Commands.doSomething;
  } catch(e) {
    return 'Some error occurred while getting the command.'
  }
}
```

## How to run

```bash
git clone https://github.com/jaimecbernardo/reproduce-rnw64-release-issue
cd reproduce-rnw64-release-issue
yarn
npx react-native run-windows
```

Expected behavior on both Debug and Release:

![image](https://user-images.githubusercontent.com/26118718/113592160-b38cab00-962c-11eb-8c52-39f5d31a6379.png)

When building for Release, the issue appears:
```bash
npx react-native run-windows --release
```
![image](https://user-images.githubusercontent.com/26118718/113592686-5e9d6480-962d-11eb-95ab-d2b992eb9a76.png)

## How the sample was built

```bash
npx react-native init ReproduceRNWReleaseBug --template react-native@^0.64.0
cd ReproduceRNWReleaseBug
npx react-native-windows-init --overwrite
```

Then the Native Module code was added and `App.js` was changed to call into it.  
This commit has those changes:  
https://github.com/jaimecbernardo/reproduce-rnw64-release-issue/commit/03c09ec886f1d998db1070b719a93f55d7ed01f0
