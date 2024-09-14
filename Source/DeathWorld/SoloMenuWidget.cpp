// Fill out your copyright notice in the Description page of Project Settings.


#include "SoloMenuWidget.h"

void USoloMenuWidget::NativeConstruct()
{
    MenuSetup();
}

void USoloMenuWidget::MenuSetup()
{
    Super::MenuSetup();
    BindButtonEvents(); 
}

void USoloMenuWidget::BindButtonEvents()
{
    // Check if EasyButton is valid and not already bound and then bind it to OnEasyButtonClicked
    if (EasyButton && !EasyButton->OnClicked.IsAlreadyBound(this, &USoloMenuWidget::OnEasyButtonClicked))
    {
        EasyButton->OnClicked.AddDynamic(this, &USoloMenuWidget::OnEasyButtonClicked);
    }

    // Check if MediumButton is valid and not already bound and then bind it to OnMediumButtonClicked
    if (MediumButton && !MediumButton->OnClicked.IsAlreadyBound(this, &USoloMenuWidget::OnMediumButtonClicked))
    {
        MediumButton->OnClicked.AddDynamic(this, &USoloMenuWidget::OnMediumButtonClicked);
    }

    // Check if HardButton is valid and not already bound and then bind it to OnHardButtonClicked
    if(HardButton && !HardButton->OnClicked.IsAlreadyBound(this, &USoloMenuWidget::OnHardButtonClicked))
    {
        HardButton->OnClicked.AddDynamic(this, &USoloMenuWidget::OnHardButtonClicked);
    }
}

void USoloMenuWidget::OnEasyButtonClicked()
{

}

void USoloMenuWidget::OnMediumButtonClicked()
{

}

void USoloMenuWidget::OnHardButtonClicked()
{

}
