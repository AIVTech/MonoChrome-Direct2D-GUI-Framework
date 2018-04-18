#include "UIView.h"


UIView::UIView(Graphics* graphics)
{
	this->graphics = graphics;
	this->r = 0.35;
	this->g = 0.35;
	this->b = 0.35;
	LoadComponents();
}

UIView::~UIView()
{

}

UIButton* clickButton;
UICheckbox* checkbox;
UISlider* slider;

void visibilityButton_OnMouseClick(UIElement* sender)
{
	clickButton->SetVisible(!clickButton->GetVisible());
	checkbox->SetVisible(!checkbox->GetVisible());
	slider->SetVisible(!slider->GetVisible());
}

void enableButton_OnMouseClick(UIElement* sender)
{
	clickButton->SetEnabled(!clickButton->GetEnabled());
	checkbox->SetEnabled(!checkbox->GetEnabled());
	slider->SetEnabled(!slider->GetEnabled());
}

int i = 0;
void button_OnMouseClick(UIElement* sender)
{
	i++;
	std::wstring text = L"Clicked Times: ";
	text.append(std::to_wstring(i));
	static_cast<UIButton*>(sender)->SetText(text);
}

void checkbox_StateChanged(UIElement* sender)
{
	UICheckbox* cbx = static_cast<UICheckbox*>(sender);
	if (cbx->GetChecked())
	{
		cbx->SetText(L"Checked");
	}
	else
	{
		cbx->SetText(L"Unchecked");
	}
}

void slider_ValueChanged(UIElement* sender)
{
	UISlider* slider = static_cast<UISlider*>(sender);
	float value = slider->GetValue();
	slider->SetRGBColor(value, value, value, value);
}

bool UIView::LoadComponents()
{

#pragma region Labels

	// Title Label
	UILabel* TitleLbl = new UILabel(graphics, L"MonoChrome Menu", L"Arial");
	TitleLbl->SetPosition(408, 16);
	TitleLbl->SetWidth(240);
	TitleLbl->SetHeight(96);
	TitleLbl->SetRGBAColor(0.365f, 0.042f, 0.042f, 1.0f);
	TitleLbl->SetTextRGBAColor(0.8f, 0.8f, 0.2f, 1.0f);
	TitleLbl->SetStroke(3);
	TitleLbl->SetFontSize(22);
	UIElements.push_back(TitleLbl);

#pragma endregion

#pragma region Buttons

	clickButton = new UIButton(graphics, L"Click Me", L"Arial", 20, 434, 200, 180, 100);
	clickButton->SetMouseClickEventHandler(button_OnMouseClick);
	UIElements.push_back(clickButton);

	UIButton* toggleButton = new UIButton(graphics, L"Toggle Visibility", L"Arial", 16, 0, 0, 200, 30);
	toggleButton->SetPosition(700, 260);
	toggleButton->SetMouseClickEventHandler(visibilityButton_OnMouseClick);
	UIElements.push_back(toggleButton);

	UIButton* enableButton = new UIButton(graphics, L"Toggle Enabled State", L"Arial", 16, 700, 220, 220, 30);
	enableButton->SetMouseClickEventHandler(enableButton_OnMouseClick);
	UIElements.push_back(enableButton);

#pragma endregion

#pragma region Checkboxes

	checkbox = new UICheckbox(graphics, L"Unchecked", L"Arial", 20, 20, 200, 30);
	checkbox->SetTextWidth(160);
	checkbox->SetTextHeight(60);
	checkbox->SetStateChangedEventHandler(checkbox_StateChanged);
	UIElements.push_back(checkbox);

#pragma endregion

#pragma region Sliders

	slider = new UISlider(graphics, 40, 360, 160);
	slider->SetMinValue(0.1f);
	slider->SetMaxValue(1.0f);
	slider->SetIntervals(0.05f);
	slider->SetValueChangedEventHandler(slider_ValueChanged);
	UIElements.push_back(slider);

	UISlider* megaSlider = new UISlider(graphics, 380, 360, 300);
	megaSlider->SetMinValue(0.1f);
	megaSlider->SetMaxValue(1.0f);
	megaSlider->SetIntervals(0.01);
	megaSlider->SetKnobRadius(slider->GetKnobRadius() + 5.0f);
	megaSlider->SetValueChangedEventHandler(slider_ValueChanged);
	UIElements.push_back(megaSlider);

#pragma endregion



	return true;
}
