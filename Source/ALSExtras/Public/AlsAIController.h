#pragma once

#include "AIController.h"
#include "RAIController.h"
#include "RAIController.h"
#include "AlsAIController.generated.h"

UCLASS(DisplayName = "Als AI Controller")
class ALSEXTRAS_API AAlsAIController  : public ARAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TObjectPtr<UBehaviorTree> BehaviorTree;

public:
	AAlsAIController();
	AAlsAIController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* NewPawn) override;

public:
	virtual FVector GetFocalPointOnActor(const AActor* Actor) const override;
};
