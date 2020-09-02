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
	
	if (!DoorTrigger) {
		UE_LOG(LogTemp, Error, TEXT("%s has the door open component on it, but no trigger selected"), *GetOwner()->GetName());
	}
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (DoorTrigger && DoorTrigger->IsOverlappingActor(ActorThatOpens)) {
		OpenDoor(DeltaTime);
	}
}

void UOpenDoor::OpenDoor(float DeltaTime) {
	// set the doors position to follow the linear interpolation
	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * 1.0f);
	// Get the doors ratator value
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	// get the doors current position
	DoorRotation.Yaw = CurrentYaw;
	// update the doors position
	GetOwner()->SetActorRotation(DoorRotation);
	// set actor rotation
}