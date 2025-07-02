using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EsperandoMultiplosCiclos : MonoBehaviour
{
    //A imagem da barra de progresso da thread
    [SerializeField] private Image _barraProgresso;
    //O objeto da mensagem de aviso
    [SerializeField] private GameObject _avisoEspera;

    private void Update()
    {
        //Se a barra estiver amarela (thread esperando)
        if (_barraProgresso.color == Color.yellow)
        {
            //Ativa a mensagem de espera
            _avisoEspera.SetActive(true);
        }
        //Se a barra estiver verde (thread avançando)
        if (_barraProgresso.color == Color.green)
        {
            //Desativa a mensagem de aviso
            _avisoEspera.SetActive(false);
            //Destrói este script
            Destroy(this);
        }
    }
}
