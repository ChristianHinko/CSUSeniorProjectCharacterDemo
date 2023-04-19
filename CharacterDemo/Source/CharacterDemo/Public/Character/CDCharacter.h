// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "CDCharacter.generated.h"


class UASActorComponent_SkinlessSkeletalMesh;
class UASActorComponent_AttachmentAttacher;



/**
 * 
 */
UCLASS()
class CHARACTERDEMO_API ACDCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category="AnimationSetup")
		TObjectPtr<UASActorComponent_SkinlessSkeletalMesh> SkinlessSkeletalMeshComponent;
	UPROPERTY(VisibleAnywhere, Category="AnimationSetup")
		TObjectPtr<UASActorComponent_AttachmentAttacher> AttachmentAttacherComponent;

public:
	ACDCharacter(const FObjectInitializer& ObjectInitializer);

	//  BEGIN AActor interface
	virtual void PostRegisterAllComponents() override;
	//  END AActor interface
};
