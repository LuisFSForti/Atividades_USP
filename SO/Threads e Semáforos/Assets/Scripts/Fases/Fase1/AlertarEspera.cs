using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AlertarEspera : MonoBehaviour
{
    //A barra de progresso da thread
    [SerializeField] private Image _barraProgresso;
    //O objeto da mensagem de aviso
    [SerializeField] private GameObject _avisoEspera;

    private void Update()
    {
        //Se a barra estiver amarela (thread esperando)
        if (_barraProgresso.color == Color.yellow)
        {
            //Ativa a mensagem
            _avisoEspera.SetActive(true);
            //Destrói este script
            Destroy(this);
        }
    }
}
