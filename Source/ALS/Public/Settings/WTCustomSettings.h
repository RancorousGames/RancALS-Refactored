#pragma once

#include "WTCustomSettings.generated.h"

USTRUCT(BlueprintType)
struct ALS_API FWTCustomSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WT", Meta = (ClampMin = 0))
	float SpineRotationBaseSpeed{50.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WT", Meta = (ClampMin = 0))
	float SpineRotationAccelerationMinimumMultiplier{0.05f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WT", Meta = (ClampMin = 0))
	float SpineRotationAccelerationTimeToFullSpeed{0.5f};

	// The higher the value, the more effect the distance to the target yaw affects the rotation speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WT", Meta = (ClampMin = 0))
	float SpineRotationLerpDistFactor{0.05f};
};
