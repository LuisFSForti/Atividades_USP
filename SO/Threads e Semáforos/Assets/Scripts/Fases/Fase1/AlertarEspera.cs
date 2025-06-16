using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AlertarEspera : MonoBehaviour
{
    [SerializeField] private Image _barraProgresso;
    [SerializeField] private GameObject _avisoEspera;

    private void Update()
    {
        if (_barraProgresso.color == Color.yellow)
        {
            _avisoEspera.SetActive(true);
            Destroy(this);
        }
    }
}
