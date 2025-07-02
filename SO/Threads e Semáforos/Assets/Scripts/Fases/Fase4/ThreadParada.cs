using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ThreadParada : MonoBehaviour
{
    //Objeto da mensagem de aviso
    [SerializeField] private GameObject _mensagem;

    //Lista das barras de progresso das threads
    private List<Image> _barrasProgressao;

    void Start()
    {
        //Pega as threads da fase
        GameObject[] threads = GameObject.FindGameObjectsWithTag("Thread");

        //Instancia a lista das imagens
        _barrasProgressao = new List<Image>();
        //Para cada controlador de imagem dos objetos-filhos
        foreach (GameObject thread in threads)
        {
            foreach (var item in thread.GetComponentsInChildren<Image>())
            {
                //Se for do tipo filled
                if (item.type == Image.Type.Filled)
                {
                    //Salva o item, pois é a barra de progresso
                    _barrasProgressao.Add(item);
                    break;
                }
            }
        }
    }

    void Update()
    {
        //Para cada barra de progresso
        foreach (Image item in _barrasProgressao)
        {
            //Se ela estiver vermelha
            if (item.color == Color.red)
            {
                //Ativa a mensagem
                _mensagem.SetActive(true);
                //Destrói este script
                Destroy(this);
            }
        }
    }
}
