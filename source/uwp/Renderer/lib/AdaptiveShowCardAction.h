#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "ShowCardAction.h"
#include "AdaptiveActionElement.h"

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{
    class DECLSPEC_UUID("429d6be9-a5f4-44dc-8dc3-3fe9b633ff1c") AdaptiveShowCardAction :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveShowCardAction,
            ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveActionElement,
            Microsoft::WRL::CloakedIid<ITypePeek>,
            Microsoft::WRL::CloakedIid<AdaptiveCards::Rendering::Uwp::AdaptiveActionElementBase>>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_Rendering_Uwp_AdaptiveShowCardAction, BaseTrust)

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(_In_ const std::shared_ptr<AdaptiveCards::ShowCardAction>& sharedShowCardAction);

        // IAdaptiveShowCardAction
        IFACEMETHODIMP get_Card(_Out_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCard** card);
        IFACEMETHODIMP put_Card(_Out_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCard* card);

        // IAdaptiveActionElement
        IFACEMETHODIMP get_ActionType(_Out_ ABI::AdaptiveCards::Rendering::Uwp::ActionType* actionType);
        IFACEMETHODIMP get_ActionTypeString(_Out_ HSTRING* value) {return AdaptiveActionElementBase::get_ActionTypeString(value);}

        IFACEMETHODIMP get_Title(_Out_ HSTRING* title) { return AdaptiveActionElementBase::get_Title(title); }
        IFACEMETHODIMP put_Title(_In_ HSTRING title) { return AdaptiveActionElementBase::put_Title(title); }

        IFACEMETHODIMP get_Id(_Out_ HSTRING* id) { return AdaptiveActionElementBase::get_Id(id); }
        IFACEMETHODIMP put_Id(_In_ HSTRING id) { return AdaptiveActionElementBase::put_Id(id); }

        IFACEMETHODIMP get_AdditionalProperties(_Out_ ABI::Windows::Data::Json::IJsonObject** result) { return AdaptiveActionElementBase::get_AdditionalProperties(result); }
        IFACEMETHODIMP put_AdditionalProperties(_In_ ABI::Windows::Data::Json::IJsonObject* value) { return AdaptiveActionElementBase::put_AdditionalProperties(value); }

        IFACEMETHODIMP ToJson(_Out_ ABI::Windows::Data::Json::IJsonObject** result) { return AdaptiveActionElementBase::ToJson(result); }

        virtual HRESULT GetSharedModel(std::shared_ptr<AdaptiveCards::BaseActionElement>& sharedModel) override;

        // ITypePeek method
        void *PeekAt(REFIID riid) override
        {
            return PeekHelper(riid, this);
        }

    private:
        
        Microsoft::WRL::ComPtr<ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCard> m_card;
    };

    ActivatableClass(AdaptiveShowCardAction);
}}}