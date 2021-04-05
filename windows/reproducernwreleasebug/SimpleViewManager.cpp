#include "pch.h"
#include "SimpleViewManager.h"

winrt::hstring winrt::reproducernwreleasebug::implementation::SimpleViewManager::Name() noexcept
{
    return L"RNSimple";
}

winrt::Windows::UI::Xaml::FrameworkElement winrt::reproducernwreleasebug::implementation::SimpleViewManager::CreateView() noexcept
{
    return winrt::Windows::UI::Xaml::Controls::Grid();
}

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

void winrt::reproducernwreleasebug::implementation::SimpleViewManager::DispatchCommand(winrt::Windows::UI::Xaml::FrameworkElement const& view, winrt::hstring const& commandId, winrt::Microsoft::ReactNative::IJSValueReader const& commandArgsReader) noexcept
{
}



