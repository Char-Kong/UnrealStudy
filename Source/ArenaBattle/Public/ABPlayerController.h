// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AABPlayerController();

	virtual void PostInitializeComponents() override;
	virtual void Possess(APawn* aPawn) override;

	class UABHUDWidget* GetHUDWidget() const;
	void NPCKill(class AABCharacter* KilledNPC) const;
	void AddGameScore() const;
	void ChangeInputMode(bool bGameMode = true);
	void ShowResultUI();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UABHUDWidget> HUDWidgetClass;

	UPROPERTY()
	TSubclassOf<class UABGamePlayWidget> MenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UABGamePlayResultWidget> ResultWidgetClass;

private:
	void OnGamePause();

	UPROPERTY()
	class UABHUDWidget* HUDWidget;

	UPROPERTY()
	class AABPlayerState* ABPlayerState;	

	UPROPERTY()
	class UABGamePlayWidget* MenuWidget;
	
	UPROPERTY()
	class UABGamePlayResultWidget* ResultWidget;

	FInputModeGameOnly GameInputMode;
	FInputModeUIOnly UIInputMode;
};
