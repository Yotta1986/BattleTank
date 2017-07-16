// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UAimComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

	UFUNCTION(BlueprintCallable, Category = Tank)
	bool GetSightRayHitLocation(FVector &HitLocation) const;

	UPROPERTY(EditDefaultsOnly, Category = Tank)
	float CrosshairXLocation = 0.5;
	
	UPROPERTY(EditDefaultsOnly, Category = Tank)
	float CrosshairYLocation = 1.0f / 3.0f;

	UPROPERTY(EditAnywhere, Category = Tank)
	float LineTraceDistance = 1000000.0f;

	bool GetLookDirection(FVector &LookDirection) const;

	bool GetLookHitLocation(const FVector &LookDirection, FVector &HitLocation) const;

	UAimComponent* AimComponent;

	UFUNCTION(BlueprintImplementableEvent, Category = "Tank")
	void FoundAimComponent(UAimComponent* AimComponent);


};
