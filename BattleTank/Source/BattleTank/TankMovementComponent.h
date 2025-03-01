// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
private:
	UTankTrack* LeftTrack;
	UTankTrack* RightTrack;

public:
	UFUNCTION(BlueprintCallable, Category = Tank)
	void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
	
	UFUNCTION(BlueprintCallable, Category = Tank)
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void IntendTurnRight(float Throw);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};
