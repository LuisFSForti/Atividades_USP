using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class DragDrop : MonoBehaviour, IPointerDownHandler, IBeginDragHandler, IEndDragHandler, IDragHandler, IDropHandler
{
    //https://www.youtube.com/watch?v=BGr-7GZJNXg
    private RectTransform _rectTransform;
    private Canvas _canvas;
    private CanvasGroup _canvasGroup;
    private Vector2 _posicaoInicial;

    //Ao ativar
    private void Awake()
    {
        //Pega as informa��es necess�rias
        _rectTransform = GetComponent<RectTransform>();
        _canvas = GameObject.Find("Canvas").GetComponent<Canvas>();
        _canvasGroup = GetComponent<CanvasGroup>();

        //Salva a posi��o inicial do recurso
        _posicaoInicial = _rectTransform.position;
    }

    //Ao come�ar a arrastar
    public void OnBeginDrag(PointerEventData eventData)
    {
        //Define que ele n�o interage com raycasts
        _canvasGroup.blocksRaycasts = false;
        //Deixa levemente transl�cido
        _canvasGroup.alpha = 0.5f;
    }

    //Enquanto estiver arrastando
    public void OnDrag(PointerEventData eventData)
    {
        //Movimenta junto com o mouse
        _rectTransform.anchoredPosition += eventData.delta / _canvas.scaleFactor * Time.timeScale;
    }

    //Ao terminar de arrastar
    public void OnEndDrag(PointerEventData eventData)
    {
        //Permite que ele interaga com raycasts
        _canvasGroup.blocksRaycasts = true;
        //Corrige a opacidade
        _canvasGroup.alpha = 1f;

        //Move de volta para a posi��o original
        //Essa movimenta��o ocorre depois de qualquer teste com raycast agir, assim permitindo a intera��o
        _rectTransform.position = _posicaoInicial;
    }

    public void OnPointerDown(PointerEventData eventData)
    {
    }

    public void OnDrop(PointerEventData eventData)
    {
    }
}
