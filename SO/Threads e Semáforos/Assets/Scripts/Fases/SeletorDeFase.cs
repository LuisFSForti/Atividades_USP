using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SeletorDeFase : MonoBehaviour
{
    [SerializeField] private int _fase;

    public void IrPraFase()
    {
        SceneManager.LoadScene(_fase);
    }
}
