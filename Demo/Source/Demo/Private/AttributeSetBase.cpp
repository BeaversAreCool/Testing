// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"

UAttributeSetBase::UAttributeSetBase()
{
	CalculateStrength();
	CalculateConstitution();
	CalculateAgility();
	CalculateIntelligence();
	CalculateIntuition();
	CalculateCharisma();
}

FGameplayAttributeData UAttributeSetBase::CalculateStrength()
{
	Strength = 500.0f;
	return Strength;
}

FGameplayAttributeData UAttributeSetBase::CalculateConstitution()
{
	Constitution = 500.0f;
	return Constitution;
}

FGameplayAttributeData UAttributeSetBase::CalculateAgility()
{
	Agility = 500.0f;
	return Agility;
}

FGameplayAttributeData UAttributeSetBase::CalculateIntelligence()
{
	Intelligence = 500.0f;
	return Intelligence;
}

FGameplayAttributeData UAttributeSetBase::CalculateIntuition()
{
	Intuition = 500.0f;
	return Intuition;
}

FGameplayAttributeData UAttributeSetBase::CalculateCharisma()
{
	Charisma = 500.0f;
	return Charisma;
}

