using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SeletorDeFase : MonoBehaviour
{
    //Fase-destino
    [SerializeField] private int _fase;

    //Carrega a fase definida
    public void IrPraFase()
    {
        SceneManager.LoadScene(_fase);
    }
}
