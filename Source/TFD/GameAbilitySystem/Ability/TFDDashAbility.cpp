// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAbilitySystem/Ability/TFDDashAbility.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h"

UTFDDashAbility::UTFDDashAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	DashingCharacter = nullptr;
}

void UTFDDashAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	// Cost와 Cooldown 체크 (현재는 둘 다 없음)
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	// 캐릭터 가져오기
	DashingCharacter = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	if (!DashingCharacter)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Dash Ability Activated!"));

	// 대시 실행 - 앞으로 발사
	FVector ForwardVector = DashingCharacter->GetActorForwardVector();
	FVector DashVelocity = ForwardVector * DashDistance;
	DashingCharacter->LaunchCharacter(DashVelocity, true, true);

	// 일정 시간 후 종료
	FTimerDelegate TimerDelegate;
	TimerDelegate.BindUFunction(this, FName("OnDashComplete"));

	DashingCharacter->GetWorldTimerManager().SetTimer(
		DashTimerHandle,
		TimerDelegate,
		DashDuration,
		false
	);
}

void UTFDDashAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	// 정리 작업
	if (DashingCharacter)
	{
		DashingCharacter->GetWorldTimerManager().ClearTimer(DashTimerHandle);
	}

	DashingCharacter = nullptr;

	UE_LOG(LogTemp, Log, TEXT("Dash Ability Ended"));

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UTFDDashAbility::OnDashComplete()
{
	UE_LOG(LogTemp, Log, TEXT("Dash completed"));
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}
