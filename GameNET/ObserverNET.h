#pragma once

#include "ModelNET.h"

public ref class ShowStepCntNET : ObserverNET
{
    Label^ lblStepCnt;

public:
    ShowStepCntNET(Label^ label) {
        lblStepCnt = label;
    }

    void event_m(ModelNET^ game) override
    {
        lblStepCnt->Text = "Count step: " + game->getStepCnt().ToString();
    }
};

public ref class ShowCollectedCoinNET : ObserverNET
{
    Label^ lblCollectedCoin;

public:
    ShowCollectedCoinNET(Label^ label) {
        lblCollectedCoin = label;
    }

    void event_m(ModelNET^ game) override
    {
        lblCollectedCoin->Text = "Coins collected: " + game->getCollectedCoins().ToString();;
    }
};

public ref class ShowHPNET : ObserverNET
{
    Label^ lblHP;

public:
    ShowHPNET(Label^ label) {
        lblHP = label;
    }

    void event_m(ModelNET^ game) override
    {
        lblHP->Text = "HP: " + game->getHp().ToString();;
    }
};

public ref class ShowAroundNET : ObserverNET
{
    Panel^ panelAround;

public:
    ShowAroundNET(Panel^ panel) {
        panelAround = panel;
    }

    void event_m(ModelNET^ game) override
    {
        game->showAround(panelAround, cout);
    }
};

public ref class ShowAllNET : ObserverNET
{
    Panel^ panelAll;

public:
    /*
    ShowAllNET(ModelNET^ game, Form^ form)
    {
        panelAll = gcnew Panel();
        panelAll->Location = *new Point(10, 10 + game->getObsDeltaY());
        panelAll->Size = *new Size(game->getLab().getW() * 13, game->getLab().getH() * 13);
        panelAll->BackColor = Color::White;
        panelAll->BorderStyle = BorderStyle::FixedSingle;
        form->Controls->Add(panelAll);
    }
    */

    ShowAllNET(Panel^ panel) {
        panelAll = panel;
    }

    void event_m(ModelNET^ game) override
    {
        game->showAll(panelAll, cout);
    }
};
