// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	// whatever the yaw is of the door at the start of the game
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	// ???
	CurrentYaw = InitialYaw;
	// This is whatever the starting yaw is + whatever amount opens the door
	TargetYaw = InitialYaw + 90.f;
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// set the doors position to follow the linear interpolation
	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, 0.02f);
	// Get the doors ratator value
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	// get the doors current position
	DoorRotation.Yaw = CurrentYaw;
	// update the doors position
	GetOwner()->SetActorRotation(DoorRotation);
	// set actor rotation




	// // define to starting rotation of the door
	// float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	// // set the axis and the value the door is to rotate along
	// FRotator OpenDoor(0.f, TargetYaw, 0.f);
	// // set the speed at which the door opens using interpolation
	// OpenDoor.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);
	// // target the door then set the rotation to the function we created
	// GetOwner()->SetActorRotation(OpenDoor);
}

