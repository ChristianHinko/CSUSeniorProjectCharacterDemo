// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CDCharacter.h"

#include "GameplayTagsManager.h"
#include "BlueprintFunctionLibraries/ASBlueprintFunctionLibrary_SkeletalMeshComponentHelpers.h"
#include "ActorComponents/ASActorComponent_SkinlessSkeletalMesh.h"
#include "ActorComponents/ASActorComponent_AttachmentAttacher.h"
#include "ActorComponents/ASActorComponent_PortrayalAssignment.h"



ACDCharacter::ACDCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set up character mesh
	UASBlueprintFunctionLibrary_SkeletalMeshComponentHelpers::ConfigureDefaultSkeletalMeshComponentTransform(GetMesh(), GetCapsuleComponent());

	SkinlessSkeletalMeshComponent = CreateDefaultSubobject<UASActorComponent_SkinlessSkeletalMesh>(TEXT("SkinlessSkeletalMeshComponent"));
	SkinlessSkeletalMeshComponent->SkeletalMeshComponentReference.ComponentProperty = TEXT("Mesh"); // NOTE: can't do GET_MEMBER_NAME_CHECKED() for the private member ACharacter::Mesh

	// Set up attachment attacher
	AttachmentAttacherComponent = CreateDefaultSubobject<UASActorComponent_AttachmentAttacher>(TEXT("AttachmentAttacherComponent"));
	AttachmentAttacherComponent->AttacheeReference.ComponentProperty = TEXT("Mesh");
}

void ACDCharacter::PostRegisterAllComponents()
{
	Super::PostRegisterAllComponents();

	AttachmentAttacherComponent->SpawnAttachments();
}
