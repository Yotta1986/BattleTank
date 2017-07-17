// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

	TankRootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{	
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//AntiSlippage();
	//UE_LOG(LogTemp, Warning, TEXT("CurrentThrottle: %f"), CurrentThrottle);
}


void UTankTrack::AntiSlippage()
{
	float SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Because we have two track
	FVector AntiSlippageAcceletation = (-SlippageSpeed / GetWorld()->GetDeltaSeconds()) * GetRightVector() / 2;

	FVector AntiSlippageForce = TankRootComponent->GetMass() * AntiSlippageAcceletation;

	TankRootComponent->AddForce(AntiSlippageForce);
}

void UTankTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & HitResult)
{
	DriveTrack();
	AntiSlippage();
	CurrentThrottle = 0;
	// reset Throttle
}

void UTankTrack::SetThrottle(float Throttle)
{
	// Keep it here! or Crash! I think it's because SetThrottle gets call before 'this' construction(we I say 'this', it means "this object TankTrack")


	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);


}

void UTankTrack::DriveTrack()
{
	if (!this) return;
	if (!TankRootComponent) return;
	auto ForceApplied = GetForwardVector() * CurrentThrottle * MaxForce;
	auto ForceLocation = GetComponentLocation();
	TankRootComponent->AddForceAtLocation(ForceApplied, ForceLocation);
}

