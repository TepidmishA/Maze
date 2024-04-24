#pragma once

#include "ModelNET.h"

public ref class ShowStepCntNET : ObserverNET
{
    Label^ lblStepCnt;

public:
    ShowStepCntNET(int x, int y, ModelNET^ game, Form^ form) {
        lblStepCnt = gcnew Label();
        lblStepCnt->Text = "Count step: " + game->getStepCnt().ToString();
        lblStepCnt->AutoSize = true;
        lblStepCnt->Location = *new Point(x, y);
        lblStepCnt->Font = gcnew Font("Arial", 12);
        form->Controls->Add(lblStepCnt);
    }

    ShowStepCntNET(ModelNET^ game, Form^ form)
    {
        lblStepCnt = gcnew Label();
        lblStepCnt->Text = "Count step: " + game->getStepCnt().ToString();
        lblStepCnt->AutoSize = true;
        lblStepCnt->Location = *new Point(10, 10 + game->getObsDeltaY());
        lblStepCnt->Font = gcnew Font("Arial", 12);
        form->Controls->Add(lblStepCnt);
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
    ShowCollectedCoinNET(int x, int y, ModelNET^ game, Form^ form)
    {
        lblCollectedCoin = gcnew Label();
        lblCollectedCoin->Text = "Coins collected: " + game->getCollectedCoins().ToString();
        lblCollectedCoin->AutoSize = true;
        lblCollectedCoin->Location = *new Point(x, y);
        lblCollectedCoin->Font = gcnew Font("Arial", 12);
        form->Controls->Add(lblCollectedCoin);
    }

    ShowCollectedCoinNET(ModelNET^ game, Form^ form)
    {
        lblCollectedCoin = gcnew Label();
        lblCollectedCoin->Text = "Coins collected: " + game->getCollectedCoins().ToString();;
        lblCollectedCoin->AutoSize = true;
        lblCollectedCoin->Location = *new Point(10, 10 + game->getObsDeltaY());
        lblCollectedCoin->Font = gcnew Font("Arial", 12);
        form->Controls->Add(lblCollectedCoin);
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
    ShowHPNET(int x, int y, ModelNET^ game, Form^ form)
    {
        lblHP = gcnew Label();
        lblHP->Text = "HP: " + game->getHp().ToString();
        lblHP->AutoSize = true;
        lblHP->Location = *new Point(x, y);
        lblHP->Font = gcnew Font("Arial", 12);
        form->Controls->Add(lblHP);
    }

    ShowHPNET(ModelNET^ game, Form^ form)
    {
        lblHP = gcnew Label();
        lblHP->Text = "HP: " + game->getHp().ToString();;
        lblHP->AutoSize = true;
        lblHP->Location = *new Point(10, 10 + game->getObsDeltaY());
        lblHP->Font = gcnew Font("Arial", 12);
        form->Controls->Add(lblHP);
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
    ShowAroundNET(ModelNET^ game, Form^ form)
    {
        panelAround = gcnew Panel();
        panelAround->Location = *new Point(10, 10 + game->getObsDeltaY());
        game->addObsDeltaY((game->getViewField() * 2) * 14);
        panelAround->Size = *new Size((game->getViewField() * 2 + 1) * 13, (game->getViewField() * 2 + 1) * 13);
        panelAround->BackColor = Color::White;
        panelAround->BorderStyle = BorderStyle::FixedSingle;

        form->Controls->Add(panelAround);
    }

    void event_m(ModelNET^ game) override
    {
        //game.paintAround(panelAround);
    }
};

public ref class ShowAllNET : ObserverNET
{
    Panel^ panelAll;

public:
    ShowAllNET(ModelNET^ game, Form^ form)
    {
        panelAll = gcnew Panel();
        panelAll->Location = *new Point(10, 10 + game->getObsDeltaY());
        panelAll->Size = *new Size(game->getLab().getW() * 13, game->getLab().getH() * 13);
        panelAll->BackColor = Color::White;
        panelAll->BorderStyle = BorderStyle::FixedSingle;
        form->Controls->Add(panelAll);
    }

    void event_m(ModelNET^ game) override
    {
        //game.paintAll(panelAll);
    }
};
