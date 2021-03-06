#include "pch.h"
#include "AdaptiveColumn.h"

#include "Util.h"
#include "Vector.h"
#include <windows.foundation.collections.h>

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::Rendering::Uwp;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI::Xaml;
using namespace ABI::Windows::UI::Xaml::Controls;

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{
    AdaptiveColumn::AdaptiveColumn()
    {
        m_items = Microsoft::WRL::Make<Vector<IAdaptiveCardElement*>>();
    }

    HRESULT AdaptiveColumn::RuntimeClassInitialize() noexcept try
    {
        std::shared_ptr<AdaptiveCards::Column> column = std::make_shared<AdaptiveCards::Column>();
        return RuntimeClassInitialize(column);
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::RuntimeClassInitialize(const std::shared_ptr<AdaptiveCards::Column>& sharedColumn) try
    {
        GenerateContainedElementsProjection(sharedColumn->GetItems(), m_items.Get());
        GenerateActionProjection(sharedColumn->GetSelectAction(), &m_selectAction);

        m_style = static_cast<ABI::AdaptiveCards::Rendering::Uwp::ContainerStyle>(sharedColumn->GetStyle());
        RETURN_IF_FAILED(UTF8ToHString(sharedColumn->GetWidth(), m_width.GetAddressOf()));

        InitializeBaseElement(std::static_pointer_cast<BaseCardElement>(sharedColumn));
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::get_Width(HSTRING* width)
    {
        return m_width.CopyTo(width);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::put_Width(HSTRING width)
    {
        return m_width.Set(width);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::get_Style(ABI::AdaptiveCards::Rendering::Uwp::ContainerStyle* style)
    {
        *style = m_style;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::put_Style(ABI::AdaptiveCards::Rendering::Uwp::ContainerStyle style)
    {
        m_style = style;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::get_Items(IVector<IAdaptiveCardElement*>** items)
    {
        return m_items.CopyTo(items);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::get_SelectAction(IAdaptiveActionElement** action)
    {
        return m_selectAction.CopyTo(action);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::put_SelectAction(IAdaptiveActionElement* action)
    {
        m_selectAction = action;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::get_ElementType(ElementType* elementType)
    {
        *elementType = ElementType::Column;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColumn::GetSharedModel(std::shared_ptr<AdaptiveCards::BaseCardElement>& sharedModel) try
    {
        std::shared_ptr<AdaptiveCards::Column> column = std::make_shared<AdaptiveCards::Column>();
        RETURN_IF_FAILED(SetSharedElementProperties(std::static_pointer_cast<AdaptiveCards::BaseCardElement>(column)));

        column->SetStyle(static_cast<AdaptiveCards::ContainerStyle>(m_style));
        column->SetWidth(HStringToUTF8(m_width.Get()));

        if (m_selectAction != nullptr)
        {
            std::shared_ptr<BaseActionElement> sharedAction;
            RETURN_IF_FAILED(GenerateSharedAction(m_selectAction.Get(), sharedAction));
            column->SetSelectAction(sharedAction);
        }

        GenerateSharedElements(m_items.Get(), column->GetItems());

        sharedModel = column;
        return S_OK;
    }CATCH_RETURN;
}}}
