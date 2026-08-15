#pragma once

#include "RigVMFunctions/RigVMFunction_ControlFlow.h"
#include "RigVMFunctions/Math/RigVMFunction_MathFloat.h"
#include "RigVMFunctions/Simulation/RigVMFunction_SimBase.h"
#include "Units/RigUnit.h"
#include "AlsRigUnits.generated.h"

/** Clamps a float to the [0, 1] range. */
USTRUCT(DisplayName = "Clamp 01", Meta = (Category = "ALS"))
struct ALS_API FAlsRigVMFunction_Clamp01Float : public FRigVMFunction_MathFloatBase
{
	GENERATED_BODY()

public:
	/** Value to clamp. */
	UPROPERTY(Meta = (Input))
	float Value{0.0f};

	/** Clamped value. */
	UPROPERTY(Meta = (Output))
	float Result{0.0f};

public:
	RIGVM_METHOD()
	virtual void Execute() override;
};

/** Smoothly interpolates a vector toward a target using exponential decay. */
USTRUCT(DisplayName = "Exponential Decay (Vector)", Meta = (Category = "ALS"))
struct ALS_API FAlsRigVMFunction_ExponentialDecayVector : public FRigVMFunction_SimBase
{
	GENERATED_BODY()

public:
	/** Destination vector. */
	UPROPERTY(Meta = (Input))
	FVector Target{ForceInit};

	/** Decay rate. */
	UPROPERTY(Meta = (Input, ClampMin = 0))
	float Lambda{1.0f};

	/** Current decayed vector. */
	UPROPERTY(Transient, Meta = (Output))
	FVector Current{ForceInit};

	UPROPERTY(Transient)
	bool bInitialized{false};

public:
	virtual void Initialize() override;

	RIGVM_METHOD()
	// ReSharper disable once CppFunctionIsNotImplemented
	virtual void Execute() override;
};

/** Smoothly interpolates a quaternion toward a target using exponential decay. */
USTRUCT(DisplayName = "Exponential Decay (Quaternion)", Meta = (Category = "ALS"))
struct ALS_API FAlsRigVMFunction_ExponentialDecayQuaternion : public FRigVMFunction_SimBase
{
	GENERATED_BODY()

public:
	/** Destination quaternion. */
	UPROPERTY(Meta = (Input))
	FQuat Target{ForceInit};

	/** Decay rate. */
	UPROPERTY(Meta = (Input, ClampMin = 0))
	float Lambda{1.0f};

	/** Current decayed quaternion. */
	UPROPERTY(Transient, Meta = (Output))
	FQuat Current{ForceInit};

	UPROPERTY(Transient)
	bool bInitialized{false};

public:
	virtual void Initialize() override;

	RIGVM_METHOD()
	// ReSharper disable once CppFunctionIsNotImplemented
	virtual void Execute() override;
};

// Calculates the projection location and direction of the perpendicular to AC through B.
USTRUCT(DisplayName = "Calculate Pole Vector", Meta = (Category = "ALS", NodeColor = "0.05 0.25 0.05"))
struct ALS_API FAlsRigUnit_CalculatePoleVector : public FRigUnit
{
	GENERATED_BODY()

public:
	UPROPERTY(Meta = (Input, ExpandByDefault))
	FRigElementKey ItemA;

	UPROPERTY(Meta = (Input, ExpandByDefault))
	FRigElementKey ItemB;

	UPROPERTY(Meta = (Input, ExpandByDefault))
	FRigElementKey ItemC;

	UPROPERTY(Meta = (Input))
	bool bInitial{false};

	UPROPERTY(Transient, Meta = (Output))
	bool bSuccess{false};

	UPROPERTY(Transient, DisplayName = "Item B Location", Meta = (Output))
	FVector ItemBLocation{ForceInit};

	UPROPERTY(Transient, DisplayName = "Item B Projection Location", Meta = (Output))
	FVector ItemBProjectionLocation{ForceInit};

	UPROPERTY(Transient, Meta = (Output))
	FVector PoleDirection{FVector::XAxisVector};

	UPROPERTY(Transient)
	FCachedRigElement CachedItemA;

	UPROPERTY(Transient)
	FCachedRigElement CachedItemB;

	UPROPERTY(Transient)
	FCachedRigElement CachedItemC;

public:
	RIGVM_METHOD()
	// ReSharper disable once CppFunctionIsNotImplemented
	virtual void Execute() override;
};

/** Branches RigVM execution based on whether the current world is a game world. */
USTRUCT(DisplayName = "Is Game World", Meta = (Category = "ALS"))
struct ALS_API FAlsRigVMFunction_IsGameWorld : public FRigVMFunction_ControlFlowBase
{
	GENERATED_BODY()

public:
	/** Execution context passed into the node. */
	UPROPERTY(Transient, DisplayName = "Execute", Meta = (Input))
	FRigVMExecuteContext ExecuteContext;

	/** Execution context for the true branch. */
	UPROPERTY(Transient, Meta = (Output))
	FRigVMExecuteContext True;

	/** Execution context for the false branch. */
	UPROPERTY(Transient, Meta = (Output))
	FRigVMExecuteContext False;

	/** Execution context for the completed branch. */
	UPROPERTY(meta=(Output))
	FRigVMExecuteContext Completed;

	UPROPERTY(Transient, Meta = (Singleton))
	FName BlockToRun;

public:
	RIGVM_METHOD()
	// ReSharper disable once CppFunctionIsNotImplemented
	virtual void Execute() override;

	virtual const TArray<FName>& GetControlFlowBlocks_Impl() const override;
};
