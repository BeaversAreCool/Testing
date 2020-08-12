// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"
#include "CharacterBase.h"

UAttributeSetBase::UAttributeSetBase()
	:Health(500.0f),
	MaxHealth(500.0f),
	Mana(500.0f),
	MaxMana(500.0f),
	Stamina(500.0f),
	MaxStamina(500.0f),
	Fatigue(500.0f),
	MaxFatigue(500.0f),
	Strength(50.0f),
	MaxStrength(50.0f),
	Constitution(50.0f),
	MaxConstitution(50.0f),
	Agility(50.0f),
	MaxAgility(50.0f),
	Intelligence(50.0f),
	MaxIntelligence(50.0f),
	Intuition(50.0f),
	MaxIntuition(50.0f),
	Charisma(50.0f),
	MaxCharisma(50.0f)	
{

}

void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0.f, MaxHealth.GetCurrentValue()));
		Health.SetBaseValue(FMath::Clamp(Health.GetBaseValue(), 0.f, MaxHealth.GetCurrentValue()));
		OnHealthChange.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
		ACharacterBase* CharacterOwner = Cast<ACharacterBase>(GetOwningActor());
		if (Health.GetCurrentValue() == MaxHealth.GetCurrentValue())
		{
			if (CharacterOwner)
			{
				CharacterOwner->AddGameplayTag(CharacterOwner->FullHealthTag);
			}
		}
		else
		{
			if (CharacterOwner)
			{
				CharacterOwner->RemoveGameplayTag(CharacterOwner->FullHealthTag);
			}
		}
	}
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Mana)))
	{
		Mana.SetCurrentValue(FMath::Clamp(Mana.GetCurrentValue(), 0.f, MaxMana.GetCurrentValue()));
		Mana.SetBaseValue(FMath::Clamp(Mana.GetBaseValue(), 0.f, MaxMana.GetCurrentValue()));
		OnManaChange.Broadcast(Mana.GetCurrentValue(), MaxMana.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Stamina)))
	{
		Stamina.SetCurrentValue(FMath::Clamp(Stamina.GetCurrentValue(), 0.f, MaxStamina.GetCurrentValue()));
		Stamina.SetBaseValue(FMath::Clamp(Stamina.GetBaseValue(), 0.f, MaxStamina.GetCurrentValue()));
		OnStaminaChange.Broadcast(Stamina.GetCurrentValue(), MaxStamina.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Fatigue)))
	{
		Fatigue.SetCurrentValue(FMath::Clamp(Fatigue.GetCurrentValue(), 0.f, MaxFatigue.GetCurrentValue()));
		Fatigue.SetBaseValue(FMath::Clamp(Fatigue.GetBaseValue(), 0.f, MaxFatigue.GetCurrentValue()));
		OnFatigueChange.Broadcast(Fatigue.GetCurrentValue(), MaxFatigue.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Fatigue)))
	{
		Strength.SetCurrentValue(FMath::Clamp(Strength.GetCurrentValue(), 0.f, MaxStrength.GetCurrentValue()));
		Strength.SetBaseValue(FMath::Clamp(Strength.GetBaseValue(), 0.f, MaxStrength.GetCurrentValue()));
		OnStrengthChange.Broadcast(Strength.GetCurrentValue(), MaxStrength.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Fatigue)))
	{
		Constitution.SetCurrentValue(FMath::Clamp(Constitution.GetCurrentValue(), 0.f, MaxConstitution.GetCurrentValue()));
		Constitution.SetBaseValue(FMath::Clamp(Constitution.GetBaseValue(), 0.f, MaxConstitution.GetCurrentValue()));
		OnConstitutionChange.Broadcast(Constitution.GetCurrentValue(), MaxConstitution.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Agility)))
	{
		Agility.SetCurrentValue(FMath::Clamp(Agility.GetCurrentValue(), 0.f, MaxAgility.GetCurrentValue()));
		Agility.SetBaseValue(FMath::Clamp(Agility.GetBaseValue(), 0.f, MaxAgility.GetCurrentValue()));
		OnAgilityChange.Broadcast(Agility.GetCurrentValue(), MaxAgility.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Intelligence)))
	{
		Intelligence.SetCurrentValue(FMath::Clamp(Intelligence.GetCurrentValue(), 0.f, MaxIntelligence.GetCurrentValue()));
		Intelligence.SetBaseValue(FMath::Clamp(Intelligence.GetBaseValue(), 0.f, MaxIntelligence.GetCurrentValue()));
		OnIntelligenceChange.Broadcast(Intelligence.GetCurrentValue(), MaxIntelligence.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Intuition)))
	{
		Intuition.SetCurrentValue(FMath::Clamp(Intuition.GetCurrentValue(), 0.f, MaxIntuition.GetCurrentValue()));
		Intuition.SetBaseValue(FMath::Clamp(Intuition.GetBaseValue(), 0.f, MaxIntuition.GetCurrentValue()));
		OnIntuitionChange.Broadcast(Intuition.GetCurrentValue(), MaxIntuition.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Charisma)))
	{
		Charisma.SetCurrentValue(FMath::Clamp(Charisma.GetCurrentValue(), 0.f, MaxCharisma.GetCurrentValue()));
		Charisma.SetBaseValue(FMath::Clamp(Charisma.GetBaseValue(), 0.f, MaxCharisma.GetCurrentValue()));
		OnCharismaChange.Broadcast(Charisma.GetCurrentValue(), MaxCharisma.GetCurrentValue());
	}


}

