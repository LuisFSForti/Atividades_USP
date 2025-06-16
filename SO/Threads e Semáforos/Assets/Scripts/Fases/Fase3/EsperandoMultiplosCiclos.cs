using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EsperandoMultiplosCiclos : MonoBehaviour
{
    [SerializeField] private Image _barraProgresso;
    [SerializeField] private GameObject _avisoEspera;

    private void Update()
    {
        if (_barraProgresso.color == Color.yellow)
        {
            _avisoEspera.SetActive(true);
        }
        if (_barraProgresso.color == Color.green)
        {
            _avisoEspera.SetActive(false);
            Destroy(this);
        }
    }
}
